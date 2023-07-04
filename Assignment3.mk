##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Assignment3
ConfigurationName      :=Debug
WorkspaceConfiguration := $(ConfigurationName)
WorkspacePath          :=/home/lukegriffin/CE4703/Assignment3
ProjectPath            :=/home/lukegriffin/CE4703/Assignment3/Assignment3
IntermediateDirectory  :=../build-$(ConfigurationName)/Assignment3
OutDir                 :=../build-$(ConfigurationName)/Assignment3
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Luke Griffin
Date                   :=05/12/22
CodeLitePath           :=/home/lukegriffin/.codelite
LinkerName             :=gcc
SharedObjectLinkerName :=gcc -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=../build-$(ConfigurationName)/bin/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :=$(IntermediateDirectory)/ObjectsList.txt
PCHCompileFlags        :=
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := gcc
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=../build-$(ConfigurationName)/Assignment3/main.c$(ObjectSuffix) ../build-$(ConfigurationName)/Assignment3/DoubleLinkedList.c$(ObjectSuffix) ../build-$(ConfigurationName)/Assignment3/OrderedIntSet.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: MakeIntermediateDirs $(OutputFile)

$(OutputFile): ../build-$(ConfigurationName)/Assignment3/.d $(Objects) 
	@mkdir -p "../build-$(ConfigurationName)/Assignment3"
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@mkdir -p "../build-$(ConfigurationName)/Assignment3"
	@mkdir -p ""../build-$(ConfigurationName)/bin""

../build-$(ConfigurationName)/Assignment3/.d:
	@mkdir -p "../build-$(ConfigurationName)/Assignment3"

PreBuild:


##
## Objects
##
../build-$(ConfigurationName)/Assignment3/main.c$(ObjectSuffix): main.c ../build-$(ConfigurationName)/Assignment3/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/lukegriffin/CE4703/Assignment3/Assignment3/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Assignment3/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Assignment3/main.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Assignment3/main.c$(DependSuffix) -MM main.c

../build-$(ConfigurationName)/Assignment3/main.c$(PreprocessSuffix): main.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Assignment3/main.c$(PreprocessSuffix) main.c

../build-$(ConfigurationName)/Assignment3/DoubleLinkedList.c$(ObjectSuffix): DoubleLinkedList.c ../build-$(ConfigurationName)/Assignment3/DoubleLinkedList.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/lukegriffin/CE4703/Assignment3/Assignment3/DoubleLinkedList.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/DoubleLinkedList.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Assignment3/DoubleLinkedList.c$(DependSuffix): DoubleLinkedList.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Assignment3/DoubleLinkedList.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Assignment3/DoubleLinkedList.c$(DependSuffix) -MM DoubleLinkedList.c

../build-$(ConfigurationName)/Assignment3/DoubleLinkedList.c$(PreprocessSuffix): DoubleLinkedList.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Assignment3/DoubleLinkedList.c$(PreprocessSuffix) DoubleLinkedList.c

../build-$(ConfigurationName)/Assignment3/OrderedIntSet.c$(ObjectSuffix): OrderedIntSet.c ../build-$(ConfigurationName)/Assignment3/OrderedIntSet.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/lukegriffin/CE4703/Assignment3/Assignment3/OrderedIntSet.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/OrderedIntSet.c$(ObjectSuffix) $(IncludePath)
../build-$(ConfigurationName)/Assignment3/OrderedIntSet.c$(DependSuffix): OrderedIntSet.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT../build-$(ConfigurationName)/Assignment3/OrderedIntSet.c$(ObjectSuffix) -MF../build-$(ConfigurationName)/Assignment3/OrderedIntSet.c$(DependSuffix) -MM OrderedIntSet.c

../build-$(ConfigurationName)/Assignment3/OrderedIntSet.c$(PreprocessSuffix): OrderedIntSet.c
	$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) ../build-$(ConfigurationName)/Assignment3/OrderedIntSet.c$(PreprocessSuffix) OrderedIntSet.c


-include ../build-$(ConfigurationName)/Assignment3//*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(IntermediateDirectory)


