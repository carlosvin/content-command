SOURCE_DIR = 'src'
SOURCES = Glob(SOURCE_DIR + '/*.c*')
INSTALL_DIR = '/usr/local/bin'

env = Environment(
	CPPPATH=[SOURCE_DIR],
	CPPDEFINES=[],
	LIBS=['grpc++_unsecure', 'grpc', 'gpr', 'protobuf', 'pthread', 'dl'],
    CXXFLAGS=['-std=c++11', '-g'],
)

prog = env.Program('bin/content_server', SOURCES)	
env.Install(INSTALL_DIR, prog)
env.Alias('install', INSTALL_DIR)
