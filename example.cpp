#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include "dis.h"
#include "event.pb.h"

#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

namespace gp = google::protobuf;

using namespace std;

int main()
{
    Event event1, event2;

    event1.set_eid(20);
   // event1.set_cid(30);

    int size = event1.ByteSize();
    printf("size = %d\n", size);

    char* buff = new char[size];
    event1.SerializeToArray(buff, size);
    dis_hexa(buff, size);

    cout << event1.ShortDebugString() << endl;

    printf("has_eid = %s\n", event1.has_eid()?"true":"false");
    printf("has_cid = %s\n", event1.has_cid()?"true":"false");

    event2.ParseFromArray(buff, 2);
    cout << event2.ShortDebugString() << endl;

    delete[] buff;

    return 0;
}
