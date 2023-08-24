CC = gcc
CXX = g++
OUTDIR = output
DLL = $(OUTDIR)/painochoclient.dll
INJ = $(OUTDIR)/painochoclient.exe
DLLDIR = dll
INJDIR = inj
DLLFLAGS = -Llib -ljvm -lopengl32 -lws2_32 -shared
INJLFLAGS = -Llib -lglfw3 -lgdi32 -lopengl32 -lws2_32 -lwindraw -lwinapiutils
CXXFLAGS = -Iinclude -std=c++23 -mwindows

CASCADESRC = $(wildcard $(DLLDIR)/cascade/*.cpp) $(wildcard $(DLLDIR)/cascade/derived/**/**/*.cpp) $(wildcard $(DLLDIR)/cascade/base/*.cpp)
DLLSRC = $(wildcard $(DLLDIR)/*.cpp) $(wildcard $(DLLDIR)/modules/*.cpp) $(CASCADESRC)
INJSRC = $(wildcard $(INJDIR)/*.cpp) $(wildcard $(INJDIR)/imgui/*.cpp) $(INJDIR)/imgui/backends/imgui_impl_glfw.cpp $(INJDIR)/imgui/backends/imgui_impl_opengl3.cpp
MHSRC = $(DLLDIR)/minhook/buffer.c $(DLLDIR)/minhook/hde64.c $(DLLDIR)/minhook/MinHook.c $(DLLDIR)/minhook/trampoline.c
MHOBJS = $(MHSRC:.c=.o)
DLLOBJS = $(DLLSRC:.cpp=.o) $(MHOBJS)
INJOBJS = $(INJSRC:.cpp=.o)
OBJDIR=obj

all: dll inj

dll: $(DLL)

$(DLL): $(DLLOBJS)
	$(CXX) -o $@ $^ $(DLLFLAGS)

inj: $(INJ)

$(INJ): $(INJOBJS)
	$(CXX) -o $@ $^ $(INJLFLAGS)

run:
	./$(OUTDIR)/painochoclient.exe
 
$(OBJDIR)/%.o: %.cpp
	$(CXX) -o $@ -c $< $(CXXFLAGS)

$(OBJDIR)/%.o: %.c
	$(CC) -o $@ -c $<

rebuild: clean dll

clean:
	del /s /q *.o
