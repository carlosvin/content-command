project('content-command', 'cpp')
add_global_arguments('-std=c++14', language : 'cpp')

#Dependencies
LIBRARIES = [find_library('zmq'), find_library('grpc++'), find_library('grpc'), find_library('gpr'), find_library('protobuf'), find_library('pthread'), find_library('dl')]

#Executables
executable('content-command', 'main.cpp', 'ServerRunner.cpp', 'ContentCmdHandlerImpl.cpp','content.grpc.pb.cc', 'content.pb.cc', dependencies : LIBRARIES)


# Build protocol buffers files
run_target('protogen', 'protos/build.proto.sh', 'protos', 'content.proto', '.')

# Tests
uuid_test = executable('uuid_test', 'test/uuid_test.cpp', 'Uuid.cpp')
test('uuid test', uuid_test)
