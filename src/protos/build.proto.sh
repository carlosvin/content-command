set -o verbose

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

GRPC_CPP_PLUGIN=grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH=`which $GRPC_CPP_PLUGIN`
PROTOS_PATH=$1
FILE_PATH=$PROTOS_PATH/$2
OUT_DIR=$3

protoc -I$PROTOS_PATH --grpc_out=$OUT_DIR --plugin=protoc-gen-grpc=$GRPC_CPP_PLUGIN_PATH $FILE_PATH
protoc -I$PROTOS_PATH --cpp_out=$OUT_DIR $FILE_PATH

