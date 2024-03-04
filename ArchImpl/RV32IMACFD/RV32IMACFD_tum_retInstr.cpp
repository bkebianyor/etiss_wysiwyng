/**
 * Generated on Mon, 04 Mar 2024 18:55:53 +0100.
 *
 * This file contains the instruction behavior models of the tum_ret
 * instruction set for the RV32IMACFD core architecture.
 */

#include "RV32IMACFDArch.h"
#include "RV32IMACFDFuncs.h"

using namespace etiss;
using namespace etiss::instr;


// ECALL -----------------------------------------------------------------------
static InstructionDefinition ecall_ (
	ISA32_RV32IMACFD,
	"ecall",
	(uint32_t) 0x000073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//ECALL\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 8LL + ((RV32IMACFD*)cpu)->PRIV);\n";
cp.code() += "etiss_coverage_count(1, 1738);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//ECALL\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "ecall" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// MRET ------------------------------------------------------------------------
static InstructionDefinition mret_ (
	ISA32_RV32IMACFD,
	"mret",
	(uint32_t) 0x30200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//MRET\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "if (((RV32IMACFD*)cpu)->PRIV < 3LL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 1793, 1791);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 2LL);\n";
cp.code() += "etiss_coverage_count(1, 1795);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[833LL];\n";
cp.code() += "etiss_coverage_count(3, 1801, 1797, 1800);\n";
cp.code() += "etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 768LL);\n";
cp.code() += "etiss_coverage_count(2, 1805, 1804);\n";
cp.code() += "etiss_uint32 prev_prv = RV32IMACFD_get_field(s, 6144LL);\n";
cp.code() += "etiss_coverage_count(2, 1810, 1809);\n";
cp.code() += "if (prev_prv != 3LL) { // conditional\n";
cp.code() += "etiss_coverage_count(2, 1813, 1811);\n";
cp.code() += "s = RV32IMACFD_set_field(s, 131072LL, 0ULL);\n";
cp.code() += "etiss_coverage_count(3, 1818, 1814, 1817);\n";
cp.code() += "} // conditional\n";
cp.code() += "if (prev_prv != ((RV32IMACFD*)cpu)->PRIV && *((RV32IMACFD*)cpu)->CSR[384LL] != 0ULL) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 1827, 1822, 1826);\n";
cp.code() += "etiss_icache_flush(cpu, system, plugin_pointers);\n";
cp.code() += "etiss_coverage_count(1, 1828);\n";
cp.code() += "} // conditional\n";
cp.code() += "s = RV32IMACFD_set_field(s, 8LL, RV32IMACFD_get_field(s, 128LL));\n";
cp.code() += "etiss_coverage_count(3, 1837, 1830, 1836);\n";
cp.code() += "s = RV32IMACFD_set_field(s, 128LL, 1ULL);\n";
cp.code() += "etiss_coverage_count(3, 1842, 1838, 1841);\n";
cp.code() += "s = RV32IMACFD_set_field(s, 6144LL, (RV32IMACFD_extension_enabled(cpu, system, plugin_pointers, 85ULL)) ? (0LL) : (3LL));\n";
cp.code() += "etiss_coverage_count(3, 1851, 1843, 1850);\n";
cp.code() += "RV32IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);\n";
cp.code() += "etiss_coverage_count(1, 1854);\n";
cp.code() += "((RV32IMACFD*)cpu)->PRIV = (prev_prv) & 0x7;\n";
cp.code() += "etiss_coverage_count(3, 1857, 1855, 1856);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//MRET\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "mret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// WFI -------------------------------------------------------------------------
static InstructionDefinition wfi_ (
	ISA32_RV32IMACFD,
	"wfi",
	(uint32_t) 0x10500073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//WFI\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//WFI\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "wfi" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);

// SRET ------------------------------------------------------------------------
static InstructionDefinition sret_ (
	ISA32_RV32IMACFD,
	"sret",
	(uint32_t) 0x10200073,
	(uint32_t) 0xffffffff,
	[] (BitArray & ba,etiss::CodeSet & cs,InstructionContext & ic)
	{

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

	{
		CodePart & cp = cs.append(CodePart::INITIALREQUIRED);

		cp.code() = std::string("//SRET\n");

// -----------------------------------------------------------------------------
{ // block
cp.code() += "{ // block\n";
cp.code() += "cpu->nextPc = " + std::to_string(ic.current_address_ + 4) + "ULL;\n";
cp.code() += "etiss_coverage_count(3, 833, 829, 832);\n";
cp.code() += "} // block\n";
} // block
{ // block
cp.code() += "{ // block\n";
cp.code() += "if (((RV32IMACFD*)cpu)->PRIV < ((RV32IMACFD_get_field(RV32IMACFD_csr_read(cpu, system, plugin_pointers, 768LL), 4194304LL)) ? (3LL) : (1LL))) { // conditional\n";
cp.code() += "etiss_coverage_count(3, 5238, 5229, 5237);\n";
{ // procedure
cp.code() += "{ // procedure\n";
cp.code() += "RV32IMACFD_raise(cpu, system, plugin_pointers, 0ULL, 2LL);\n";
cp.code() += "etiss_coverage_count(1, 5240);\n";
cp.code() += "goto instr_exit_" + std::to_string(ic.current_address_) + ";\n";
cp.code() += "} // procedure\n";
} // procedure
cp.code() += "} // conditional\n";
cp.code() += "cpu->nextPc = *((RV32IMACFD*)cpu)->CSR[321LL];\n";
cp.code() += "etiss_coverage_count(3, 5246, 5242, 5245);\n";
cp.code() += "etiss_uint32 s = RV32IMACFD_csr_read(cpu, system, plugin_pointers, 256LL);\n";
cp.code() += "etiss_coverage_count(2, 5250, 5249);\n";
cp.code() += "etiss_uint32 prev_prv = RV32IMACFD_get_field(s, 256LL);\n";
cp.code() += "etiss_coverage_count(2, 5255, 5254);\n";
cp.code() += "s = RV32IMACFD_set_field(s, 2LL, RV32IMACFD_get_field(s, 32LL));\n";
cp.code() += "etiss_coverage_count(3, 5263, 5256, 5262);\n";
cp.code() += "s = RV32IMACFD_set_field(s, 32LL, 1ULL);\n";
cp.code() += "etiss_coverage_count(3, 5268, 5264, 5267);\n";
cp.code() += "s = RV32IMACFD_set_field(s, 256LL, 0LL);\n";
cp.code() += "etiss_coverage_count(3, 5274, 5269, 5273);\n";
cp.code() += "RV32IMACFD_csr_write(cpu, system, plugin_pointers, 768LL, s);\n";
cp.code() += "etiss_coverage_count(1, 5277);\n";
cp.code() += "((RV32IMACFD*)cpu)->PRIV = (prev_prv) & 0x7;\n";
cp.code() += "etiss_coverage_count(3, 5280, 5278, 5279);\n";
cp.code() += "} // block\n";
} // block
cp.code() += "instr_exit_" + std::to_string(ic.current_address_) + ":\n";
cp.code() += "cpu->instructionPointer = cpu->nextPc;\n";
// -----------------------------------------------------------------------------
		cp.getAffectedRegisters().add("instructionPointer", 32);
	}
	{
		CodePart & cp = cs.append(CodePart::APPENDEDRETURNINGREQUIRED);

		cp.code() = std::string("//SRET\n");

// -----------------------------------------------------------------------------
cp.code() += "return cpu->exception;\n";
// -----------------------------------------------------------------------------
	}

		return true;
	},
	0,
	[] (BitArray & ba, Instruction & instr)
	{
// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

		std::stringstream ss;
// -----------------------------------------------------------------------------
ss << "sret" << " # " << ba << (" []");
// -----------------------------------------------------------------------------
		return ss.str();
	}
);
