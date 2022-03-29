package com.example.ffmpeg_test;

import android.os.Bundle;

import androidx.appcompat.app.AppCompatActivity;

import com.example.ffmpeg_test.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());
        binding.sampleText.setText(ffmpegInfo());
    }

    public native String ffmpegInfo();

}