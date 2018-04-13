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
	for (int i=0; i<desc->field_count(); i++)
	{
        const auto* field_desc = desc->field(i);
        const gp::FieldOptions& field_option = field_desc->options();
        bool required = field_option.GetExtension(producer_required);
        int fsize = field_option.GetExtension(fix_size);

        printf("field [%s] :  %-10s \t%d\n", field_desc->name().c_str(), required?"required":"no required", fsize);
	}

    delete[] buff;

    return 0;
}
