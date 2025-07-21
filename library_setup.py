import os
import re

class Variable:
    type = ""
    name = ""
    size = ""

    def __init__(self, line):
        parts = line.split(' ')
        self.type = parts[0]

        #if (parts[0] == "TexturePtr"):
        #    self.size = "[]"
        
        if (parts[1][-1:] == ']'):
            index = parts[1].index('[')

            self.name = parts[1][0:index]
            self.size += parts[1][index:]
        else:
            self.name = parts[1]
    
    def __str__(self):
        return f"{self.type} {self.name}{self.size}"
    
    def as_standard(self):
        return self.name[1:]
    
    def as_pointer(self):
        return f"p{self.as_standard()}"
    
    def as_call(self):
        return f"{self.as_standard()}_Register"
    
    def as_register(self):
        return f"void {self.as_call()}({self.type} (**pointer){variable.size})"
    
    def as_macro(self):
        return '_'.join(re.split('(?<=.)(?=[A-Z])', self.as_standard())).upper()

print("Make sure that example.c and interface_helper.h are in the example folder before pressing enter.")
input()

variables = []

for entry in os.scandir("./src"):
    if entry.name[-2:] == ".c":
        with open(entry, "r") as library:
            for line in library:
                if (line[0] != ' ') and ('=' in line):
                    variables.append(Variable(line))

library =   "#include \"modding.h\"\n"
library +=  "#include \"global.h\""

header =    "#ifndef INTERFACE_HELPER\n"
header +=   "#define INTERFACE_HELPER\n\n"
header += library

for variable in variables:
    library += "\n\n"
    library += f"extern {variable};\n"
    library += "\n"
    library += f"RECOMP_EXPORT " + variable.as_register() + "\n"
    library += "{\n"
    library += f"  *pointer = &{variable.name};\n"
    library += "}"
    
    header += "\n\n"
    header += f"#define {variable.as_macro()}_DECLARE RECOMP_IMPORT(\"mm_recomp_interface_helper\", {variable.as_register()}); \\\n"
    header += f"{variable.type} (*{variable.as_pointer()}){variable.size};\n"
    header += "\n"
    header += f"#define {variable.as_macro()}_REGISTER {variable.as_call()}(&{variable.as_pointer()});"

header +=   "\n\n#endif // INTERFACE_HELPER"

with open("./src/library.c", "w") as lib_file:
    lib_file.write(library)

with open("./example/interface_helper.h", "w") as head_file:
    head_file.write(header)

print("Header and library files updated.")