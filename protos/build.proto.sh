set -o verbose

GRPC_CPP_PLUGIN=grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH=`which $GRPC_CPP_PLUGIN`
PROTOS_PATH=.
OUT_DIR=.

protoc -I$PROTOS_PATH --grpc_out=$OUT_DIR --plugin=protoc-gen-grpc=$GRPC_CPP_PLUGIN_PATH $1
protoc -I$PROTOS_PATH --cpp_out=$OUT_DIR $1

mv -f *.h $2/headers
mv -f *.cc $2/cpp
