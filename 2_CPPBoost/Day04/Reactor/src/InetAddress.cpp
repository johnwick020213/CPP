#include "../include/InetAddress.h"

 InetAddress::InetAddress(const string &ip,unsigned short port) {

}

 InetAddress::InetAddress(const struct sockaddr_in &addr) {

}

 InetAddress::~InetAddress() {

}

string InetAddress::ip() const {

}

unsigned short InetAddress::port()const {

}

const struct sockaddr_in InetAddress::*getInetAddPtr() {

}

