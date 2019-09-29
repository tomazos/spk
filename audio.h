#pragma once

class AudioSystem {
 public:
  AudioSystem() {
    SDL_AudioSpec desired, obtained;
    SDL_memset(&desired, 0, sizeof(desired));
    desired.format = AUDIO_F32;
    desired.freq = 48000;
    desired.channels = 2;
    desired.samples = 128;
    desired.callback = generate_audio;
    desired.userdata = this;

    device_id = SDL_OpenAudioDevice(nullptr /*device*/, false /*iscapture*/,
                                    &desired, &obtained, 0 /*allow changes*/);
    SDL_PauseAudioDevice(device_id, 0 /*pause_on*/);
    DVC_ASSERT(device_id != 0);
  }

  ~AudioSystem() { SDL_CloseAudioDevice(device_id); }

 private:
  static void generate_audio(void* userdata, Uint8* char_stream, int len) {
    ((AudioSystem*)userdata)->generate_audio(char_stream, len);
  }

  void generate_audio(Uint8* char_stream, int len) {
    float* float_stream = (float*)char_stream;

    static size_t current_sample = 0;
    DVC_ASSERT(len % (4 * 2) == 0);
    size_t num_samples = len / (4 * 2);

    for (size_t i = 0; i < num_samples; i++, current_sample++) {
      for (size_t channel = 0; channel < 2; channel++) {
        float_stream[i * 2 + channel] =
            generate_sample(double(current_sample) / 48000, channel);
      }
    }
  }

  double generate_sample(double t, size_t channel) {
    static PAudioWave wave =
        reshape(round_wave(), 0.5, 128) + reshape(round_wave(), 0.5, 256) +
        reshape(round_wave(), 0.25, 512) + reshape(round_wave(), 0.125, 1024);
    return wave->sample(t, channel);
  }

  SDL_AudioDeviceID device_id;
};
