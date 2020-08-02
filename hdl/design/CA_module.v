module cavium_CA(
input a,
input b,
input c,
input rule_number,
output x);
	reg temp;
	always @* begin
		if (rule_number == 3'b000) begin
			temp = a ^ b ^ c ^ (b & c);
		end else if (rule_number == 3'b001) begin
			temp = a ^ b;
		end else if (rule_number == 3'b010) begin
			temp = a ^ c;
		end else if (rule_number == 3'b011) begin
			temp = a ^ (b & c);
		end else if (rule_number == 3'b100) begin
			temp = a ^ b ^ c;
		end else if (rule_number == 3'b101) begin
			temp = a ^ b ^ (b & c);
		end else if (rule_number == 3'b110) begin
			temp = a ^ c ^ (b & c);
		end else if (rule_number == 3'b111) begin
			temp = a;
		end
	end
	assign x = temp;
endmodule