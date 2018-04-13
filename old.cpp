#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include "old_event.pb.h"

#include <google/protobuf/io/zero_copy_stream_impl_lite.h>

namespace gp = google::protobuf;

using namespace std;

int main()
{
    Event event1;
    event1.set_eid(30);
    event1.set_cid(500);
    event1.set_xid(10000);

    printf("Is valid : %s\n", event1.IsInitialized()?"ok":"nok");

    cout << event1.ShortDebugString() << endl;

	fstream output("myfile", ios::out | ios::binary);
	event1.SerializeToOstream(&output);

    return 0;
}
