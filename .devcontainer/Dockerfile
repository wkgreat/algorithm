from mcr.microsoft.com/devcontainers/base:jammy

COPY source.list.aliyun /etc/apt/sources.list

RUN sudo apt-get update && \
    sudo apt-get remove -y libelf1 && \
    sudo apt-get install -y gdb node.js