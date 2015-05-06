"""
Build
"""
SOURCE_DIR = 'src'
SOURCE_MAIN = Glob(SOURCE_DIR + '/main.cpp')
SOURCES_LIB = Glob(SOURCE_DIR + '/*.c*')
SOURCES_LIB.remove(SOURCE_MAIN[0])

env = Environment(
	CPPPATH=[SOURCE_DIR],
	LIBS=['grpc++', 'grpc', 'gpr', 'protobuf', 'pthread', 'dl'],
    CXXFLAGS=['-std=c++11', '-g'],
)

prog = env.Program('bin/content_server', [SOURCE_MAIN, SOURCES_LIB ])	

"""
Unit tests
https://raw.githubusercontent.com/philsquared/Catch/develop/single_include/catch.hpp
"""
TEST_DIR = 'test'
TEST_SOURCES = Glob(TEST_DIR + '/*.c*')

import os
test_env = env.Clone(
					CPPPATH=[TEST_DIR, SOURCE_DIR],
					ENV=os.environ
					)

test_program = test_env.Program('bin/uuid_test', [TEST_SOURCES, SOURCES_LIB])
AlwaysBuild(test_env.Alias('test', [test_program], test_program[0].abspath))

"""
Install
"""
INSTALL_DIR = '/usr/local/bin'
env.Install(INSTALL_DIR, prog)
env.Alias('install', INSTALL_DIR)
