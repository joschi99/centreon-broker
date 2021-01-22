#!/usr/bin/python3
import grpc
import broker_pb2
import broker_pb2_grpc
import sys
from google.protobuf import empty_pb2

def run():
  with grpc.insecure_channel("127.0.0.1:{}".format(sys.argv[1])) as channel:
    stub = broker_pb2_grpc.BrokerStub(channel)
    v = stub.GetStats(broker_pb2.StatsQuery(
          query = { broker_pb2.StatsQuery.ENGINE }
          ))
    print(v)
run()
