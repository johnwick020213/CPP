#include "../include/EventLoop.h"

 EventLoop::EventLoop(Acceptor &acceptor) {

}

 EventLoop::~EventLoop() {

}

void EventLoop::loop() {

}

void EventLoop::unloop() {

}

void EventLoop::waitEpollFd() {

}

void EventLoop::handleNewConnection() {

}

void EventLoop::handleMessage(int fd) {

}

int EventLoop::createEpollFd() {

}

void EventLoop::addEpollReadFd(int fd) {

}

void EventLoop::delEpollReadFd(int fd) {

}

void EventLoop::setNewConnectionCallback(TcpConnectionCallback &&cb) {

}

void EventLoop::setMessageCallback(TcpConnectionCallback &&cb) {

}

void EventLoop::setCloseCallback(TcpConnectionCallback &&cb) {

}

int EventLoop::createEventFd() {

}

void EventLoop::handleRead() {

}

void EventLoop::wakeup() {

}

void EventLoop::doPengdingFuntors() {

}

void EventLoop::runInLoop(Functors &&cb) {

}

