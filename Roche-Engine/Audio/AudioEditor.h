#pragma once
#ifndef AUDIOEDITOR_H
#define AUDIOEDITOR_H

#include "Audio/AudioEngine.h"

#include "JsonLoading.h"

class AudioEditor
{
public:
#if _DEBUG
	AudioEditor();
	~AudioEditor();
	void SortScreens();
	void SpawnControlWindow();
	void SaveToFileSoundBankLists();
	void LoadFromFileSoundBankLists();
	//void SaveToFileSoundBankFiles();
	void SpawnSoundBankWindow(AudioType audioType);

	
	void SetJsonFile( const std::string& name ); // Will load default sound bank (used by level editor)

	// sound bank handle
	void LoadSoundFileInfoFromJSON(std::string loadFilePath);
	void SaveSoundFileInfoToJSON(std::string fileName);

#endif // _DEBUG
private:
	std::string m_sFilePath;
	std::string m_sFileContent;
	std::string m_sSelectedFile;
	std::string m_sSoundBankFile = "!SoundBankList.json";

	std::vector<std::string> m_vSoundTypes = { "SFX", "MUSIC" };

	std::string m_sActiveSoundBankList;
	std::string m_sActiveSoundBankPath;

	std::vector<SoundBanksList> m_vSoundBanksList; // list of Sound Bank Lists
	std::vector<JSONSoundFile> m_vSoundFileInfo;
	//std::map<std::string, std::vector<JSONSoundFile>> m_vSoundFileData; // list of Sound Files for a given Sound Bank

	bool m_bSoundBankToLoad;
	//bool m_bIsSoundBankReloaded;
	int m_iActiveSoundBankIndex;
};

#endif // AUDIOEDITOR_H