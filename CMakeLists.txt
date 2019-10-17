cmake_minimum_required(VERSION 3.3)
project(muduo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(./)

set(SOURCE_FILES examples/cdns/dns.cc
        muduo/base/Atomic.h
        muduo/base/BlockingQueue.h
        muduo/base/BoundedBlockingQueue.h
        muduo/base/copyable.h
        muduo/base/GzipFile.h
        muduo/base/Mutex.h
        muduo/base/noncopyable.h
        muduo/base/Singleton.h
        muduo/base/StringPiece.h
        muduo/base/ThreadLocal.h
        muduo/base/ThreadLocalSingleton.h
        muduo/base/Types.h
        muduo/base/WeakCallback.h
        muduo/net/http/HttpRequest.h
        muduo/net/protobuf/BufferStream.h
        muduo/net/Endian.h
        muduo/net/Callbacks.h
        muduo/net/TimerId.h
        muduo/net/ZlibStream.h)
AUX_SOURCE_DIRECTORY(muduo/base SOURCE_FILES)
AUX_SOURCE_DIRECTORY(muduo/net SOURCE_FILES)
AUX_SOURCE_DIRECTORY(muduo/net/http SOURCE_FILES)
AUX_SOURCE_DIRECTORY(muduo/net/inspect SOURCE_FILES)
AUX_SOURCE_DIRECTORY(muduo/net/poller SOURCE_FILES)
AUX_SOURCE_DIRECTORY(muduo/net/protorpc SOURCE_FILES)
AUX_SOURCE_DIRECTORY(muduo/net/protobuf SOURCE_FILES)

ADD_EXECUTABLE(muduo ${SOURCE_FILES})






