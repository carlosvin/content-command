env = Environment(
	CPPPATH=['src/content_server/headers'],
	CPPDEFINES=[],
	LIBS=['grpc++_unsecure', 'grpc', 'gpr', 'protobuf', 'pthread', 'dl'],
    CXXFLAGS=['-std=c++11', '-g'],
	#LIBPATH=["/usr/lib", "/usr/local/lib", '/usr/lib64'],
    #LINKFLAGS="--static"
)

CPP_BASE = "src/content_server/cpp/"

env.Program('content_server', Glob(CPP_BASE + '*.c*'))	
