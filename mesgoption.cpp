#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "dis.h"
#include "event2.pb.h"

#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/descriptor.h>

namespace gp = google::protobuf;

using namespace std;

int main()
{
    Event event1;
    event1.set_eid(20);
    event1.set_cid(30);

    int size = event1.ByteSize();
    printf("size = %d\n", size);

    char* buff = new char[size];
    event1.SerializeToArray(buff, size);
    dis_hexa(buff, size);

    cout << event1.ShortDebugString() << endl;

    const auto* desc = event1.GetDescriptor();
    const gp::MessageOptions& mesg_option = desc->options();
    Type msg_type = mesg_option.GetExtension(type);
    int msg_id = mesg_option.GetExtension(id);
    printf("type = %d\n", (int)msg_type);
    printf("id   = %d\n", (int)msg_id);

    delete[] buff;

    return 0;
}
