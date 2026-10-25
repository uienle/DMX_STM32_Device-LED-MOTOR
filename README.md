# STM32 DMX512 Receiver — LED/Motor Control Node

**Embedded Firmware | STM32F103C8T6 | C | DMX512 | RS-485**

## Overview

This project implements a DMX512 receiver (RX) node using the STM32F103C8T6 microcontroller and an RS-485 transceiver.

Each RX node controls one device: an RGB LED using three DMX channels or a motor using one DMX channel. All RX nodes receive the same DMX512 data stream and store the received channel values in a buffer. Each node selects the channel values assigned to its device and updates the corresponding GPIO outputs in the main loop.

The transmitter (TX) handles the system-level control algorithm and determines the DMX channel values used to control multiple devices simultaneously.

## System Architecture

- **Transmitter (TX):** Executes the control algorithm and transmits DMX512 channel data.
- **Receiver (RX):** Receives DMX512 data, stores channel values in a buffer, selects the data assigned to its device, and updates GPIO outputs.
- **RGB LED node:** Uses three DMX channels to control red, green, and blue.
- **Motor node:** Uses one DMX channel for motor control.

Each RX node controls one device. Coordination between multiple devices is handled by the TX.

## Receiver Processing Flow

1. Receive DMX512 data through the RS-485 interface.
2. Store the received channel values in a buffer.
3. Select the channel values assigned to the connected device.
4. Update the corresponding GPIO outputs in the main loop.

**Data flow:** DMX512 Reception → Channel Buffer → Channel Selection → GPIO Output Update

## Key Features

- DMX512 data reception through RS-485.
- Buffer-based storage of received channel values.
- Device-specific DMX channel selection.
- GPIO output updates in the main loop.
- Shared reception logic with different output handling for RGB LED and motor nodes.

## Hardware and Development Tools

- **Microcontroller:** STM32F103C8T6
- **Communication interface:** RS-485
- **Protocol:** DMX512
- **Programming language:** C
- **IDE:** STM32CubeIDE
- **Firmware library:** STM32 HAL

## Repository Contents

This repository contains the RX firmware source code and STM32CubeIDE project configuration.

---

## Tiếng Việt

### Tổng quan

Dự án triển khai firmware cho node nhận DMX512 (RX), sử dụng vi điều khiển STM32F103C8T6 và bộ thu phát RS-485.

Mỗi node RX điều khiển một thiết bị: LED RGB sử dụng ba kênh DMX hoặc motor sử dụng một kênh DMX. Tất cả các node RX đều nhận cùng một luồng dữ liệu DMX512 và lưu các giá trị channel vào buffer. Mỗi node chọn các giá trị channel được gán cho thiết bị của mình và cập nhật các chân GPIO tương ứng trong vòng lặp chính.

Bộ phát (TX) đảm nhiệm thuật toán điều khiển tổng thể, quyết định giá trị các kênh DMX để nhiều thiết bị có thể hoạt động đồng thời.

### Kiến trúc hệ thống

- **Bộ phát (TX):** Thực thi thuật toán điều khiển và gửi dữ liệu các kênh DMX512.
- **Bộ nhận (RX):** Nhận dữ liệu DMX512, lưu các giá trị channel vào buffer, chọn dữ liệu dành cho thiết bị và cập nhật đầu ra GPIO.
- **Node LED RGB:** Sử dụng ba kênh DMX để điều khiển ba thành phần màu đỏ, xanh lá và xanh dương.
- **Node motor:** Sử dụng một kênh DMX để điều khiển motor.

Mỗi node RX phụ trách một thiết bị. Việc phối hợp điều khiển nhiều thiết bị do TX đảm nhiệm.

### Luồng xử lý của RX

1. Nhận dữ liệu DMX512 qua giao tiếp RS-485.
2. Lưu các giá trị channel nhận được vào buffer.
3. Chọn các channel được gán cho thiết bị kết nối với node.
4. Cập nhật các chân GPIO tương ứng trong vòng lặp chính.

**Luồng dữ liệu:** Nhận DMX512 → Lưu channel vào buffer → Chọn channel → Cập nhật đầu ra GPIO

### Phần cứng và công cụ phát triển

- **Vi điều khiển:** STM32F103C8T6
- **Giao tiếp:** RS-485
- **Giao thức:** DMX512
- **Ngôn ngữ lập trình:** C
- **IDE:** STM32CubeIDE
- **Thư viện firmware:** STM32 HAL

### Nội dung repository

Repository bao gồm mã nguồn firmware RX và các file cấu hình dự án STM32CubeIDE.
