package com.example.q1;

import androidx.appcompat.app.AppCompatActivity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.GridView;

public class MainActivity extends AppCompatActivity {
    int[] items = {R.drawable.logo1,R.drawable.logo1,R.drawable.logo1,R.drawable.logo1,R.drawable.logo1,R.drawable.logo1,
            R.drawable.logo1,R.drawable.logo1,R.drawable.logo10,R.drawable.logo11,R.drawable.logo13,R.drawable.logo15,
            R.drawable.logo10,R.drawable.logo11,R.drawable.logo13,R.drawable.logo15,R.drawable.logo10,
            R.drawable.logo11,R.drawable.logo13,R.drawable.logo15};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        GridView gv = (GridView) findViewById(R.id.gv);

    }
}