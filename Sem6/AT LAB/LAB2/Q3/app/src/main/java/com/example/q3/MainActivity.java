package com.example.q3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.constraintlayout.widget.ConstraintLayout;

import android.os.Bundle;
import android.view.View;
import android.widget.LinearLayout;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public  void red(View v)
    {
        ConstraintLayout ll = (ConstraintLayout) findViewById(R.id.LL);
        ll.setBackgroundResource(R.color.red);
    }
    public  void blue(View v)
    {
        ConstraintLayout ll = (ConstraintLayout) findViewById(R.id.LL);
        ll.setBackgroundResource(R.color.blue);
    }
    public  void yellow(View v)
    {
        ConstraintLayout ll = (ConstraintLayout) findViewById(R.id.LL);
        ll.setBackgroundResource(R.color.yellow);
    }
    public  void green(View v)
    {
        ConstraintLayout ll = (ConstraintLayout) findViewById(R.id.LL);
        ll.setBackgroundResource(R.color.green);
    }
}