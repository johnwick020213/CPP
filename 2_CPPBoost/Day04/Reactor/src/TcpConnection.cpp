#include "../include/TcpConnection.h"

 TcpConnection::TcpConnection(int fd,EventLoop *loop) {

}

 TcpConnection::~TcpConnection() {

}

void TcpConnection::send(const string &msg) {

}

void TcpConnection::sendInLoop(const string &msg) {

}

string TcpConnection::receive() {

}

string TcpConnection::toString() {

}

void TcpConnection::setNewConnectionCallback(const TcpConnectionCallback &cb) {

}

void TcpConnection::setMessageCallback(const TcpConnectionCallback &cb) {

}

void TcpConnection::setCloseCallback(const TcpConnectionCallback &cb) {

}

void TcpConnection::handleNewConnetionCallback() {

}

void TcpConnection::handleMessageCallback() {

}

void TcpConnection::handleCloseCallback() {

}

InetAddress TcpConnection::getLocalAddr() {

}

InetAddress TcpConnection::getPeerAddr() {

}

