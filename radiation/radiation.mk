##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=radiation
ConfigurationName      :=Debug
WorkspacePath          :=/home/hudson/Documentos/radiation
ProjectPath            :=/home/hudson/Documentos/radiation/radiation
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=hudson
Date                   :=26/02/18
CodeLitePath           :=/home/hudson/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="radiation.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
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
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/realizationProblem.cpp$(ObjectSuffix) $(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hudson/Documentos/radiation/radiation/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/realizationProblem.cpp$(ObjectSuffix): realizationProblem.cpp $(IntermediateDirectory)/realizationProblem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hudson/Documentos/radiation/radiation/realizationProblem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/realizationProblem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/realizationProblem.cpp$(DependSuffix): realizationProblem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/realizationProblem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/realizationProblem.cpp$(DependSuffix) -MM realizationProblem.cpp

$(IntermediateDirectory)/realizationProblem.cpp$(PreprocessSuffix): realizationProblem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/realizationProblem.cpp$(PreprocessSuffix) realizationProblem.cpp

$(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(ObjectSuffix): src/algorithms/realizationAlgorithm/gsc.cpp $(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/hudson/Documentos/radiation/radiation/src/algorithms/realizationAlgorithm/gsc.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(DependSuffix): src/algorithms/realizationAlgorithm/gsc.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(DependSuffix) -MM src/algorithms/realizationAlgorithm/gsc.cpp

$(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(PreprocessSuffix): src/algorithms/realizationAlgorithm/gsc.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_algorithms_realizationAlgorithm_gsc.cpp$(PreprocessSuffix) src/algorithms/realizationAlgorithm/gsc.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


