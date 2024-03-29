#include <stdint.h>

#if 0
/home/armand/..dev/VkShaderRendering/Hologram/Hologram.push_constant.vert
// Module Version 10000
// Generated by (magic number): 8000a
// Id's are bound by 31

                              Capability Shader
               1:             ExtInstImport  "GLSL.std.450"
                              MemoryModel Logical GLSL450
                              EntryPoint Vertex 4  "main" 11 20
                              Source ESSL 310
                              Name 4  "main"
                              Name 9  "world_pos"
                              Name 11  "in_pos"
                              Name 18  "gl_PerVertex"
                              MemberName 18(gl_PerVertex) 0  "gl_Position"
                              MemberName 18(gl_PerVertex) 1  "gl_PointSize"
                              Name 20  ""
                              Decorate 11(in_pos) Location 0
                              MemberDecorate 18(gl_PerVertex) 0 BuiltIn Position
                              MemberDecorate 18(gl_PerVertex) 1 BuiltIn PointSize
                              Decorate 18(gl_PerVertex) Block
               2:             TypeVoid
               3:             TypeFunction 2
               6:             TypeFloat 32
               7:             TypeVector 6(float) 3
               8:             TypePointer Function 7(fvec3)
              10:             TypePointer Input 7(fvec3)
      11(in_pos):     10(ptr) Variable Input
              17:             TypeVector 6(float) 4
18(gl_PerVertex):             TypeStruct 17(fvec4) 6(float)
              19:             TypePointer Output 18(gl_PerVertex)
              20:     19(ptr) Variable Output
              21:             TypeInt 32 1
              22:     21(int) Constant 0
              24:    6(float) Constant 1065353216
              29:             TypePointer Output 17(fvec4)
         4(main):           2 Function None 3
               5:             Label
    9(world_pos):      8(ptr) Variable Function
              12:    7(fvec3) Load 11(in_pos)
              13:    6(float) CompositeExtract 12 0
              14:    6(float) CompositeExtract 12 1
              15:    6(float) CompositeExtract 12 2
              16:    7(fvec3) CompositeConstruct 13 14 15
                              Store 9(world_pos) 16
              23:    7(fvec3) Load 9(world_pos)
              25:    6(float) CompositeExtract 23 0
              26:    6(float) CompositeExtract 23 1
              27:    6(float) CompositeExtract 23 2
              28:   17(fvec4) CompositeConstruct 25 26 27 24
              30:     29(ptr) AccessChain 20 22
                              Store 30 28
                              Return
                              FunctionEnd
#endif

static const uint32_t Hologram_push_constant_vert[209] = {
    0x07230203, 0x00010000, 0x0008000a, 0x0000001f,
    0x00000000, 0x00020011, 0x00000001, 0x0006000b,
    0x00000001, 0x4c534c47, 0x6474732e, 0x3035342e,
    0x00000000, 0x0003000e, 0x00000000, 0x00000001,
    0x0007000f, 0x00000000, 0x00000004, 0x6e69616d,
    0x00000000, 0x0000000b, 0x00000014, 0x00030003,
    0x00000001, 0x00000136, 0x00040005, 0x00000004,
    0x6e69616d, 0x00000000, 0x00050005, 0x00000009,
    0x6c726f77, 0x6f705f64, 0x00000073, 0x00040005,
    0x0000000b, 0x705f6e69, 0x0000736f, 0x00060005,
    0x00000012, 0x505f6c67, 0x65567265, 0x78657472,
    0x00000000, 0x00060006, 0x00000012, 0x00000000,
    0x505f6c67, 0x7469736f, 0x006e6f69, 0x00070006,
    0x00000012, 0x00000001, 0x505f6c67, 0x746e696f,
    0x657a6953, 0x00000000, 0x00030005, 0x00000014,
    0x00000000, 0x00040047, 0x0000000b, 0x0000001e,
    0x00000000, 0x00050048, 0x00000012, 0x00000000,
    0x0000000b, 0x00000000, 0x00050048, 0x00000012,
    0x00000001, 0x0000000b, 0x00000001, 0x00030047,
    0x00000012, 0x00000002, 0x00020013, 0x00000002,
    0x00030021, 0x00000003, 0x00000002, 0x00030016,
    0x00000006, 0x00000020, 0x00040017, 0x00000007,
    0x00000006, 0x00000003, 0x00040020, 0x00000008,
    0x00000007, 0x00000007, 0x00040020, 0x0000000a,
    0x00000001, 0x00000007, 0x0004003b, 0x0000000a,
    0x0000000b, 0x00000001, 0x00040017, 0x00000011,
    0x00000006, 0x00000004, 0x0004001e, 0x00000012,
    0x00000011, 0x00000006, 0x00040020, 0x00000013,
    0x00000003, 0x00000012, 0x0004003b, 0x00000013,
    0x00000014, 0x00000003, 0x00040015, 0x00000015,
    0x00000020, 0x00000001, 0x0004002b, 0x00000015,
    0x00000016, 0x00000000, 0x0004002b, 0x00000006,
    0x00000018, 0x3f800000, 0x00040020, 0x0000001d,
    0x00000003, 0x00000011, 0x00050036, 0x00000002,
    0x00000004, 0x00000000, 0x00000003, 0x000200f8,
    0x00000005, 0x0004003b, 0x00000008, 0x00000009,
    0x00000007, 0x0004003d, 0x00000007, 0x0000000c,
    0x0000000b, 0x00050051, 0x00000006, 0x0000000d,
    0x0000000c, 0x00000000, 0x00050051, 0x00000006,
    0x0000000e, 0x0000000c, 0x00000001, 0x00050051,
    0x00000006, 0x0000000f, 0x0000000c, 0x00000002,
    0x00060050, 0x00000007, 0x00000010, 0x0000000d,
    0x0000000e, 0x0000000f, 0x0003003e, 0x00000009,
    0x00000010, 0x0004003d, 0x00000007, 0x00000017,
    0x00000009, 0x00050051, 0x00000006, 0x00000019,
    0x00000017, 0x00000000, 0x00050051, 0x00000006,
    0x0000001a, 0x00000017, 0x00000001, 0x00050051,
    0x00000006, 0x0000001b, 0x00000017, 0x00000002,
    0x00070050, 0x00000011, 0x0000001c, 0x00000019,
    0x0000001a, 0x0000001b, 0x00000018, 0x00050041,
    0x0000001d, 0x0000001e, 0x00000014, 0x00000016,
    0x0003003e, 0x0000001e, 0x0000001c, 0x000100fd,
    0x00010038,
};
