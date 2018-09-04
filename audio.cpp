#include "audio.h"


Audio::Audio() {
	SDL_Init(SDL_INIT_AUDIO);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 4096);
}

Audio::~Audio() {
	for (int i = 0; i < Audio_Names.size(); i++) {
		Mix_FreeChunk(Audio_Files.find(Audio_Names[i])->second);
	}
	Mix_CloseAudio();
	SDL_Quit();
}

const void Audio::LoadWAV(const std::string Audio_Name, const char* audiofile) {
	Audio_Files[Audio_Name] = Mix_LoadWAV(audiofile);
	Audio_Names.push_back(Audio_Name);
}

void Audio::playAudioChannel(const std::string Audio_Name, const int channel, const int playNum) {
	Mix_PlayChannel(channel, Audio_Files.find(Audio_Name)->second, playNum);
}

void Audio::playAudio(const std::string Audio_Name, const int playNum) {
	Mix_PlayChannel(-1, Audio_Files.find(Audio_Name)->second, playNum);
}

void Audio::pauseAudio(const int channel) {
	Mix_Pause(channel);
}









/*
Audio::Audio(){
	SDL_Init(SDL_INIT_AUDIO);
}

Audio::~Audio(){

	for (int i = 0; i < Audio_Names.size(); i++) {
		Audio_Files.find(Audio_Names[i]);
		SDL_CloseAudioDevice(Audio_Files.find(Audio_Names[i])->second.au_ID);
		SDL_FreeWAV(Audio_Files.find(Audio_Names[i])->second.au_buffer);
	}
	Audio_Names.clear();
}

void Audio::playAudio(const std::string Audio_Name) {
	SDL_QueueAudio(Audio_Files.find(Audio_Name)->second.au_ID, Audio_Files.find(Audio_Name)->second.au_buffer, Audio_Files.find(Audio_Name)->second.au_length);
	SDL_PauseAudioDevice(Audio_Files.find(Audio_Name)->second.au_ID, 0);
}

void Audio::stopAudio(const std::string Audio_Name) {
	SDL_CloseAudioDevice(Audio_Files.find(Audio_Name)->second.au_ID);
}

const void Audio::CreateAudio(const std::string Audio_Name, const char* audiofile) {
	Audio_Effect tempAudio;

	if (Audio_Files.find(Audio_Name)->first == Audio_Name) {
		std::cout << "AUDIO NAME \"" << Audio_Name << "\" ALREADY EXISTS, AUDIO FILE NOT LOADED" << std::endl;
	}
	else {
		bool success;
		success=SDL_LoadWAV(audiofile, &tempAudio.au_audio, &tempAudio.au_buffer, &tempAudio.au_length);
		if (success) {
			tempAudio.au_ID = SDL_OpenAudioDevice(NULL, 0, &tempAudio.au_audio, NULL, 0);
			Audio_Files[Audio_Name] = tempAudio;
			Audio_Names.push_back(Audio_Name);
		}else
		{
			std::cout << "FAIL TO LOAD "<<audiofile << std::endl;
		}
	}

}
*/