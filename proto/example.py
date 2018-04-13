#!/usr/bin/python

import event_pb2

event = event_pb2.Event()


f = open("myfile", "rb")
event.ParseFromString(f.read())

print event

f.close();
