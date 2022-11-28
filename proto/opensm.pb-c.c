/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: opensm.proto */

/* Do not generate deprecated warnings for self */
#ifndef PROTOBUF_C__NO_DEPRECATED
#define PROTOBUF_C__NO_DEPRECATED
#endif

#include "opensm.pb-c.h"
void   port__init
                     (Port         *message)
{
  static const Port init_value = PORT__INIT;
  *message = init_value;
}
size_t port__get_packed_size
                     (const Port *message)
{
  assert(message->base.descriptor == &port__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t port__pack
                     (const Port *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &port__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t port__pack_to_buffer
                     (const Port *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &port__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Port *
       port__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Port *)
     protobuf_c_message_unpack (&port__descriptor,
                                allocator, len, data);
}
void   port__free_unpacked
                     (Port *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &port__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   node__init
                     (Node         *message)
{
  static const Node init_value = NODE__INIT;
  *message = init_value;
}
size_t node__get_packed_size
                     (const Node *message)
{
  assert(message->base.descriptor == &node__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t node__pack
                     (const Node *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &node__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t node__pack_to_buffer
                     (const Node *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &node__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
Node *
       node__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (Node *)
     protobuf_c_message_unpack (&node__descriptor,
                                allocator, len, data);
}
void   node__free_unpacked
                     (Node *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &node__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
void   store_message__init
                     (StoreMessage         *message)
{
  static const StoreMessage init_value = STORE_MESSAGE__INIT;
  *message = init_value;
}
size_t store_message__get_packed_size
                     (const StoreMessage *message)
{
  assert(message->base.descriptor == &store_message__descriptor);
  return protobuf_c_message_get_packed_size ((const ProtobufCMessage*)(message));
}
size_t store_message__pack
                     (const StoreMessage *message,
                      uint8_t       *out)
{
  assert(message->base.descriptor == &store_message__descriptor);
  return protobuf_c_message_pack ((const ProtobufCMessage*)message, out);
}
size_t store_message__pack_to_buffer
                     (const StoreMessage *message,
                      ProtobufCBuffer *buffer)
{
  assert(message->base.descriptor == &store_message__descriptor);
  return protobuf_c_message_pack_to_buffer ((const ProtobufCMessage*)message, buffer);
}
StoreMessage *
       store_message__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data)
{
  return (StoreMessage *)
     protobuf_c_message_unpack (&store_message__descriptor,
                                allocator, len, data);
}
void   store_message__free_unpacked
                     (StoreMessage *message,
                      ProtobufCAllocator *allocator)
{
  if(!message)
    return;
  assert(message->base.descriptor == &store_message__descriptor);
  protobuf_c_message_free_unpacked ((ProtobufCMessage*)message, allocator);
}
static const ProtobufCFieldDescriptor port__field_descriptors[1] =
{
  {
    "portGuid",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(Port, portguid),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned port__field_indices_by_name[] = {
  0,   /* field[0] = portGuid */
};
static const ProtobufCIntRange port__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor port__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Port",
  "Port",
  "Port",
  "",
  sizeof(Port),
  1,
  port__field_descriptors,
  port__field_indices_by_name,
  1,  port__number_ranges,
  (ProtobufCMessageInit) port__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor node__field_descriptors[1] =
{
  {
    "ports",
    1,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(Node, n_ports),
    offsetof(Node, ports),
    &port__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned node__field_indices_by_name[] = {
  0,   /* field[0] = ports */
};
static const ProtobufCIntRange node__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 1 }
};
const ProtobufCMessageDescriptor node__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "Node",
  "Node",
  "Node",
  "",
  sizeof(Node),
  1,
  node__field_descriptors,
  node__field_indices_by_name,
  1,  node__number_ranges,
  (ProtobufCMessageInit) node__init,
  NULL,NULL,NULL    /* reserved[123] */
};
static const ProtobufCFieldDescriptor store_message__field_descriptors[3] =
{
  {
    "timestamp",
    1,
    PROTOBUF_C_LABEL_NONE,
    PROTOBUF_C_TYPE_UINT64,
    0,   /* quantifier_offset */
    offsetof(StoreMessage, timestamp),
    NULL,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "ports",
    2,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(StoreMessage, n_ports),
    offsetof(StoreMessage, ports),
    &port__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
  {
    "nodes",
    3,
    PROTOBUF_C_LABEL_REPEATED,
    PROTOBUF_C_TYPE_MESSAGE,
    offsetof(StoreMessage, n_nodes),
    offsetof(StoreMessage, nodes),
    &node__descriptor,
    NULL,
    0,             /* flags */
    0,NULL,NULL    /* reserved1,reserved2, etc */
  },
};
static const unsigned store_message__field_indices_by_name[] = {
  2,   /* field[2] = nodes */
  1,   /* field[1] = ports */
  0,   /* field[0] = timestamp */
};
static const ProtobufCIntRange store_message__number_ranges[1 + 1] =
{
  { 1, 0 },
  { 0, 3 }
};
const ProtobufCMessageDescriptor store_message__descriptor =
{
  PROTOBUF_C__MESSAGE_DESCRIPTOR_MAGIC,
  "StoreMessage",
  "StoreMessage",
  "StoreMessage",
  "",
  sizeof(StoreMessage),
  3,
  store_message__field_descriptors,
  store_message__field_indices_by_name,
  1,  store_message__number_ranges,
  (ProtobufCMessageInit) store_message__init,
  NULL,NULL,NULL    /* reserved[123] */
};
