import React from "react";
import "antd/dist/antd.css";
import { Modal, Button } from "antd";
import EditForm from "./editform";


class AddItemModal extends React.Component {
  state = {};
  showModal = () => {this.setState({ visible: true });};
  handleCancel = () => {this.setState({ visible: false });};

  render() {
    const { visible, confirmLoading } = this.state;
    return (
      <>
        <Button type="primary" onClick={this.showModal}>
          Add Todo
        </Button>
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

export default AddItemModal;
