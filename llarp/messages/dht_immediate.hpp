#ifndef LLARP_MESSAGES_DHT_IMMEDIATE_HPP
#define LLARP_MESSAGES_DHT_IMMEDIATE_HPP
#include <dht.hpp>
#include <link_message.hpp>

#include <vector>

namespace llarp
{
  struct DHTImmeidateMessage : public ILinkMessage
  {
    DHTImmeidateMessage() : ILinkMessage()
    {
    }

    ~DHTImmeidateMessage();

    std::vector< std::unique_ptr< llarp::dht::IMessage > > msgs;

    bool
    DecodeKey(llarp_buffer_t key, llarp_buffer_t* buf) override;

    bool
    BEncode(llarp_buffer_t* buf) const override;

    bool
    HandleMessage(llarp::Router* router) const override;

    void
    Clear() override;
  };
}  // namespace llarp

#endif
