package com.example.q2;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void click(View v)
    {
        TextView tv = (TextView) findViewById(R.id.textView);
        EditText et = (EditText) findViewById(R.id.editTextTextPersonName);
        String wrd = String.valueOf(et.getText());
        char a;
        String word="";
        for(int i=0;i<wrd.length();i++)
        {
            a=wrd.charAt(i);
            a+=1;
            if(a>'z')
                a-=26;
            word+=a;
        }
        tv.setText(word);
    }
}