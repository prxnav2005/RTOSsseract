// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// -------------------------------------------------------------------------------

`timescale 1 ps / 1 ps

(* BLOCK_STUB = "true" *)
module RTOS_Block (
  dip_switches_4bits_tri_i,
  usb_uart_rxd,
  usb_uart_txd,
  Clk,
  reset,
  led_4bits_tri_o
);

  (* X_INTERFACE_INFO = "xilinx.com:interface:gpio:1.0 dip_switches_4bits TRI_I" *)
  (* X_INTERFACE_MODE = "master dip_switches_4bits" *)
  input [3:0]dip_switches_4bits_tri_i;
  (* X_INTERFACE_INFO = "xilinx.com:interface:uart:1.0 usb_uart RxD" *)
  (* X_INTERFACE_MODE = "master usb_uart" *)
  input usb_uart_rxd;
  (* X_INTERFACE_INFO = "xilinx.com:interface:uart:1.0 usb_uart TxD" *)
  output usb_uart_txd;
  (* X_INTERFACE_INFO = "xilinx.com:signal:clock:1.0 CLK.CLK CLK" *)
  (* X_INTERFACE_MODE = "slave CLK.CLK" *)
  (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME CLK.CLK, FREQ_HZ 100000000, FREQ_TOLERANCE_HZ 0, PHASE 0.0, CLK_DOMAIN RTOS_Block_Clk, INSERT_VIP 0" *)
  input Clk;
  (* X_INTERFACE_INFO = "xilinx.com:signal:reset:1.0 RST.RESET RST" *)
  (* X_INTERFACE_MODE = "slave RST.RESET" *)
  (* X_INTERFACE_PARAMETER = "XIL_INTERFACENAME RST.RESET, POLARITY ACTIVE_LOW, INSERT_VIP 0" *)
  input reset;
  (* X_INTERFACE_INFO = "xilinx.com:interface:gpio:1.0 led_4bits TRI_O" *)
  (* X_INTERFACE_MODE = "master led_4bits" *)
  output [3:0]led_4bits_tri_o;

  // stub module has no contents

endmodule
