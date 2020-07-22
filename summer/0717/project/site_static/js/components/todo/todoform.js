import React from "react";
import "antd/dist/antd.css";
import { Modal, Button, Select, Form, Input, Divider, Row, Col, message } from "antd";

const { Option } = Select;
const layout = { labelCol: { span: 5 }, wrapperCol: { span: 19 } };

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
    }, 2500);
    setTimeout(() => {
      message.success("Todo item created!", 0.8);
    }, 2750);
  };

  render() {
    const { loadings } = this.state;
    return (
      <Form
        {...layout} ref={this.formRef} name="control-ref" preserve={false}
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
                type="primary" loading={loadings[0]} onClick={() => this.enterLoading(0)}
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

class EditModal extends React.Component {
  state = {};
  showModal = () => {this.setState({ visible: true });};
  handleCancel = () => {this.setState({ visible: false });};

  render() {
    const { visible, confirmLoading } = this.state;
    return (
      <>
        <span onClick={this.showModal}>{this.props.title}</span>
        <Modal
          title="Edit Todo Item" visible={visible}
          confirmLoading={confirmLoading} onCancel={this.handleCancel}
          footer={[null]}
        >
          <EditForm />
        </Modal>
      </>
    );
  }
}

export default EditModal;
