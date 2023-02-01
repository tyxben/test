
#ifdef __cplusplus

#include <iostream>
#include <string>

// usage code
#endif
#include "teevm_message.pb.h"
#include "foo.h"
#define constexpr const
std::string serialize(std::string id, int32_t name)
{
    std::cout << "serialize" << std::endl;
    // std::byte b2{0b1111'0000};
    // std::map<std::string, std::string> mapPerson;
    // mapPerson["21"] = "3232";
    teevm::TeeVMMessage msg;
    msg.set_chain_id("1");
    msg.set_type(teevm::TeeVMType::COMPLETED);
    // test::test test;
    // test.set_id(id);
    // test.set_name(name);
    // // test.set_result(b2);
    // test.mutable_payload()->insert(google::protobuf::MapPair<std::string, std::string>("1", "r"));
    // // test::TxContext kk;

    teevm::TxRequest *kk = new teevm::TxRequest;
    kk->set_method("add");
    msg.set_allocated_request(kk);
    // kk->mutable_write_map()->insert(google::protobuf::MapPair<std::string, std::string>("2", "q"));
    // kk->mutable_read_map()->insert(google::protobuf::MapPair<std::string, std::string>("3", "w"));
    // test.set_allocated_kk(kk);
    //.mutable_kk()->write_map()->insert(google::protobuf::MapPair<std::string, std::string>("2", "q"));
    // 序列化操作
    // std::string data;
    // std::ostream *stream;
    auto data = msg.SerializeAsString();
    std::cout << "serialize === data" << data << std::endl;
    const char *bytes = data.c_str();

    auto r = add(bytes);
    std::cout << "out === r:=" << r << std::endl;
    // auto sk = std::string(r, 12);
    // std::cout << "serialize2 === r:=" << sk << std::endl;
    // std::cout << "out === r:=" << out << std::endl;
    // test::test test1;
    // std::string data2(out, out + strlen(out));
    teevm::TeeVMMessage test1;
    // 反序列化操作
    test1.ParseFromString(r);
    // test1.ParseFromString(out);
    std::cout << "serialize2 === data2" << test1.SerializeAsString() << std::endl;
    // std::string data2;
    // test1.SerializeToString(&data2);
    // std::cout << "serialize2 === data2" << data2 << std::endl;
    return data;
}
void deserialization(std::string data)
{
    std::cout << "deserialize" << std::endl;
    teevm::TeeVMMessage test;
    // 反序列化操作
    test.ParseFromString(data);

    std::cout << test.chain_id() << std::endl;
    std::cout << test.tx_id() << std::endl;
}

int main()
{
    std::string data = serialize("01", 132);

    deserialization(data);

    google::protobuf::ShutdownProtobufLibrary(); // 删除所有已分配的内存

    return 0;
}
