//CAvium CA module testbench
`include "../design/CA_module.v"

module cavium_CA_tb;
	reg a, b, c;
	reg [2:0] rule_num;
	wire z;

	cavium_CA cavium_CA_inst(
		.a(a),
		.b(b),
		.c(c),
		.rule_number(rule_num),
		.z(z)
	);

	initial begin
		a = 1'b1;
		b = 1'b1;
		c = 1'b1;
		rule_num[2:0] = 3b'111;
		#10; //delay
		$display("%d",z);
	end
endmodule