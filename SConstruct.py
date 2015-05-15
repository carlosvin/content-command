
SOURCE_DIR = 'src'
SOURCE_MAIN = Glob(SOURCE_DIR + '/main.cpp')
SOURCES_LIB = Glob(SOURCE_DIR + '/*.c*')
SOURCES_LIB.remove(SOURCE_MAIN[0])
LIBRARIES = ['grpc++', 'grpc', 'gpr', 'protobuf', 'pthread', 'dl']

env = Environment(
	CPPPATH=[SOURCE_DIR],
	LIBS=LIBRARIES,
    CXXFLAGS=['-std=c++11', '-g'],
)

"""
Generate proto files
"""
GRPC_CPP_PLUGIN="grpc_cpp_plugin"
GRPC_CPP_PLUGIN_PATH="`which $GRPC_CPP_PLUGIN`"
PROTOS_PATH="protos"
PROTO_FILE=PROTOS_PATH + "/content.proto"

cmd1 = "protoc -I%s --grpc_out=%s --plugin=protoc-gen-grpc=%s %s" % (PROTOS_PATH, SOURCE_DIR, GRPC_CPP_PLUGIN_PATH, PROTO_FILE)
cmd2 = "protoc -I%s --cpp_out=%s %s" % (PROTOS_PATH, SOURCE_DIR, PROTO_FILE)

env.Command("cmd1", None, cmd1)
env.Command("cmd2", None, cmd2)

"""
Build
"""
lib  = env.StaticLibrary('lib/content_server', [SOURCES_LIB])
LIBRARIES.append(lib)
prog = env.Program('bin/content_server', [SOURCE_MAIN], LIBS=LIBRARIES)

"""
Unit tests
https://raw.githubusercontent.com/philsquared/Catch/develop/single_include/catch.hpp
"""
TEST_DIR = 'test'
TEST_SOURCES = Glob(TEST_DIR + '/*.c*')

import os
test_env = env.Clone(
    CPPPATH=[TEST_DIR, SOURCE_DIR],
    ENV=os.environ)

test_program = test_env.Program('bin/uuid_test', [TEST_SOURCES], LIBS=LIBRARIES)
AlwaysBuild(test_env.Alias('test', [test_program], test_program[0].abspath))

"""
Install
"""
INSTALL_DIR = '/usr/local/bin'
env.Install(INSTALL_DIR, prog)
env.Alias('install', INSTALL_DIR)
