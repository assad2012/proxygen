/*
 *  Copyright (c) 2016, Facebook, Inc.
 *  All rights reserved.
 *
 *  This source code is licensed under the BSD-style license found in the
 *  LICENSE file in the root directory of this source tree. An additional grant
 *  of patent rights can be found in the PATENTS file in the same directory.
 *
 */
#include <proxygen/lib/http/session/test/TestUtils.h>

using folly::test::MockAsyncTransport;

using namespace folly;

namespace proxygen {

const wangle::TransportInfo mockTransportInfo = wangle::TransportInfo();
const SocketAddress localAddr{"127.0.0.1", 80};
const SocketAddress peerAddr{"127.0.0.1", 12345};

folly::HHWheelTimer::UniquePtr makeInternalTimeoutSet(EventBase* evb) {
  folly::HHWheelTimer::UniquePtr t(
    new folly::HHWheelTimer(evb,
                            std::chrono::milliseconds(
                              folly::HHWheelTimer::DEFAULT_TICK_INTERVAL),
                            TimeoutManager::InternalEnum::INTERNAL,
                            std::chrono::milliseconds(500)));
  t->setCatchupEveryN(1);
  return t;
}

folly::HHWheelTimer::UniquePtr makeTimeoutSet(EventBase* evb) {
  folly::HHWheelTimer::UniquePtr t(
    new folly::HHWheelTimer(evb,
                            std::chrono::milliseconds(
                              folly::HHWheelTimer::DEFAULT_TICK_INTERVAL),
                            folly::AsyncTimeout::InternalEnum::NORMAL,
                            std::chrono::milliseconds(500)));
  t->setCatchupEveryN(1);
  return t;
}

testing::NiceMock<MockAsyncTransport>* newMockTransport(EventBase* evb) {
  auto transport = new testing::NiceMock<MockAsyncTransport>();
  EXPECT_CALL(*transport, getEventBase())
    .WillRepeatedly(testing::Return(evb));
  return transport;
}

}
