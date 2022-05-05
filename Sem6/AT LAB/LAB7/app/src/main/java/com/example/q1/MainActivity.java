package com.example.q1;

import androidx.appcompat.app.AppCompatActivity;

import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

public class MainActivity extends AppCompatActivity {
EditText name, roll, score;
Button add, update, delete, view;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        SQLiteDatabase mydatabase = openOrCreateDatabase("Practice",MODE_PRIVATE,null);
        mydatabase.execSQL("CREATE TABLE IF NOT EXISTS Student(roll VARCHAR primary key, name VARCHAR, marks VARCHAR);");
//        mydatabase.execSQL("INSERT INTO Student VALUES('11','Ashish', 85);");
        name = findViewById(R.id.name);
        roll = findViewById(R.id.roll);
        score = findViewById(R.id.score);
        add = findViewById(R.id.add);
        update = findViewById(R.id.update);
        delete = findViewById(R.id.delete);
        view = findViewById(R.id.view);
//        String name1,roll1,score1;
//        name1 = name.getText().toString();
//        roll1 = roll.getText().toString();
//        score1 = score.getText().toString();
        add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String name1 = name.getText().toString();
                String roll1 = roll.getText().toString();
                String score1 = score.getText().toString();
                mydatabase.execSQL("INSERT INTO Student VALUES('"+roll1+"','"+name1+"', '"+score1+"');");
            }
        });
        delete.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String roll1 = roll.getText().toString();
                mydatabase.execSQL("DELETE FROM Student WHERE roll = '"+roll1+"'");
            }
        });
        update.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String name1 = name.getText().toString();
                String roll1 = roll.getText().toString();
                String score1 = score.getText().toString();
                mydatabase.execSQL("Update Student set name = '"+name1+"', marks = '"+score1+"' where roll = '"+roll1+"'");
            }
        });
        view.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String roll1 = roll.getText().toString();
                Cursor resultSet = mydatabase.rawQuery("Select * from student where roll = '"+roll1+"' ",null);
                resultSet.moveToFirst();
                name.setText(resultSet.getString(1));
                score.setText(resultSet.getString(2));
                Log.d("Hello",roll1);
            }
        });
    }
}