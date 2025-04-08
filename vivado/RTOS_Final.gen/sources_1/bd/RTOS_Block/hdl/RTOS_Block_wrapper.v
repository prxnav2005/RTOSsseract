//Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
//Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
//--------------------------------------------------------------------------------
//Tool Version: Vivado v.2024.2.2 (lin64) Build 6060944 Thu Mar 06 19:10:09 MST 2025
//Date        : Sun Apr  6 13:03:05 2025
//Host        : archlinux running 64-bit Arch Linux
//Command     : generate_target RTOS_Block_wrapper.bd
//Design      : RTOS_Block_wrapper
//Purpose     : IP block netlist
//--------------------------------------------------------------------------------
`timescale 1 ps / 1 ps

module RTOS_Block_wrapper
   (Clk,
    dip_switches_4bits_tri_i,
    led_4bits_tri_o,
    reset,
    usb_uart_rxd,
    usb_uart_txd);
  input Clk;
  input [3:0]dip_switches_4bits_tri_i;
  output [3:0]led_4bits_tri_o;
  input reset;
  input usb_uart_rxd;
  output usb_uart_txd;

  wire Clk;
  wire [3:0]dip_switches_4bits_tri_i;
  wire [3:0]led_4bits_tri_o;
  wire reset;
  wire usb_uart_rxd;
  wire usb_uart_txd;

  RTOS_Block RTOS_Block_i
       (.Clk(Clk),
        .dip_switches_4bits_tri_i(dip_switches_4bits_tri_i),
        .led_4bits_tri_o(led_4bits_tri_o),
        .reset(reset),
        .usb_uart_rxd(usb_uart_rxd),
        .usb_uart_txd(usb_uart_txd));
endmodule
