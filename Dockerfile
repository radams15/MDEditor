FROM ubuntu:18.04

RUN apt-get update && apt-get install -y gcc g++ cmake make libwxgtk3.0-dev libwxgtk-webview3.0-dev