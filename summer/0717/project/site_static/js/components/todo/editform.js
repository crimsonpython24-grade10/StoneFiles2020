import React from "react";
import "antd/dist/antd.css";
import { Button, Select, Form, Input, Divider, Row, Col, message } from "antd";
import jQuery from "jquery";

const { Option } = Select;
const layout = { labelCol: { span: 5 }, wrapperCol: { span: 19 } };

function getCookie(name) {
  let cookieValue = null;
  if (document.cookie && document.cookie !== '') {
    let cookies = document.cookie.split(';');
    for (let i = 0; i < cookies.length; i++) {
      let cookie = jQuery.trim(cookies[i]);
      if (cookie.substring(0, name.length + 1) === (name + '=')) {
          cookieValue = decodeURIComponent(cookie.substring(name.length + 1));
          break;
      }
    }
  }
  return cookieValue;
}

var csrftoken = getCookie('csrftoken');

async function postData(url = '', data = {}) {
  let csrftoken = getCookie('csrftoken');

  const formData = new FormData();
  formData.append('method', data.method);
  formData.append('title', data.title);
  formData.append('desc', data.desc);
  formData.append('level', data.level);

  const response = await fetch(url, {
    method: 'POST',
    credentials: 'include',
    mode: 'same-origin',
    headers: {'X-CSRFToken': csrftoken,},
    body: formData
  });
  return response.json();
}

class EditForm extends React.Component {
  constructor(props) {
    super(props);
    this.state = {
      title: "", desc: "", level: "normal",
      titleProps: {}, descProps: {}, levelProps: {}, loadings: []
    };
    this.handleTitleChange = this.handleTitleChange.bind(this);
    this.handleDescChange = this.handleDescChange.bind(this);
    this.handleLvlChange = this.handleLvlChange.bind(this);
  }

  formRef = React.createRef();

  handleTitleChange(event) {
    this.setState({ title: event.target.value });
    if (event.target.value === "") {
      this.setState({
        titleProps: {
          hasFeedback: true, validateStatus: "warning",
          help: "Title cannot be empty"
        }
      });
    } else {this.setState({ titleProps: {} });}
  }
  handleDescChange(event) {
    this.setState({ desc: event.target.value });
  }
  handleLvlChange(value) {this.setState({ level: value });}

  enterLoading = index => {
    this.setState(({ loadings }) => {
      const newLoadings = [...loadings];
      newLoadings[index] = true;
      return { loadings: newLoadings };
    });
    setTimeout(() => {
      this.setState(({ loadings }) => {
        const newLoadings = [...loadings];
        newLoadings[index] = false;
        return { loadings: newLoadings };
      });
    }, 1800);
    setTimeout(() => {
      message.success("Todo item created!", 0.8);
    }, 2050);
  };

  handleSubmit = (event) => {
    setTimeout(() => {
      event => event.preventDefault();
      postData('/todo/', {
        title: this.state.title, desc: this.state.desc,
        level: this.state.level, method: 'edit'
      })
      .then(data => {
        if (data.success) {window.location = '/todo/';}
      });
    }, 2850);
  }

  render() {
    const { loadings } = this.state;
    return (
      <Form
        {...layout} ref={this.formRef} name="control-ref" preserve={false}
        onFinish={this.handleSubmit}
      >
        <Form.Item
          name="title" label="Title"  {...this.state.titleProps}
          onChange={this.handleTitleChange}
        >
          <Input placeholder="Title" />
        </Form.Item>
        <Form.Item
          name="desc" label="Description" {...this.state.descProps}
          onChange={this.handleDescChange}
        >
          <Input.TextArea placeholder="Description" />
        </Form.Item>
        <Form.Item name="level" label="Level">
          <Select
            placeholder="Select..." initialvalue="normal" preserve="false"
            onChange={this.handleLvlChange}
          >
            <Option value="important">Important</Option>
            <Option value="normal">Normal</Option>
            <Option value="unimportant">Not Important</Option>
          </Select>
        </Form.Item>
        <Divider />
        <Row justify="end" align="top">
          <Col>
            <Form.Item style={{ marginTop: -14 }}>
              <Button
                type="primary" htmlType="submit" loading={loadings[0]} onClick={() => this.enterLoading(0)}
              >
                Submit
              </Button>
            </Form.Item>
          </Col>
        </Row>
      </Form>
    );
  }
}

export default EditForm;