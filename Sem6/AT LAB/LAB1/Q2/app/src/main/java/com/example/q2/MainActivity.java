package com.example.q2;

import android.content.DialogInterface;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Patterns;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;
import android.widget.Toast;
public class MainActivity extends AppCompatActivity {

    private EditText name, email, phone, password;
    private Button button;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
    public void onClickBtn(View v)
    {
        name = findViewById(R.id.name);
        email = findViewById(R.id.email);
        phone = findViewById(R.id.mobile);
        password = findViewById(R.id.password);
        String email_id = String.valueOf(email.getText());String full_name = String.valueOf(name.getText());
        String mobile_no = String.valueOf(phone.getText());
        String pass = String.valueOf(password.getText());
        boolean validEmail = !TextUtils.isEmpty(email_id) && Patterns.EMAIL_ADDRESS.matcher(email_id).matches();
        boolean validNumber = true;
        if(mobile_no.length()==10)
        {
            for(int i=0;i<10;i++)
            {
                if(mobile_no.charAt(i)>='0' && mobile_no.charAt(i)<='9')
                    continue;
                else {
                    validNumber = false;
                    break;
                }
            }
        }
        else
            validNumber = false;
        boolean validName = !TextUtils.isEmpty(full_name);
        boolean validPassword = !TextUtils.isEmpty(pass);
        boolean allValid = validEmail && validNumber && validName && validPassword;
        if (!validEmail){
            email.setError("Invalid Email");
        }
        if (!validNumber){
            phone.setError("Phone Number Should be of 10 digits");
        }
        if (!validName){
            name.setError("This field cannot be empty");
        }
        if (!validPassword){
            password.setError("This field cannot be empty");
        }
        if(allValid) {
            Toast.makeText(getApplicationContext(), "Welcome " + name.getText(), Toast.LENGTH_SHORT).show();
        } else {
            Toast.makeText(getApplicationContext(), "Invalid Entries found", Toast.LENGTH_SHORT).show();
        }
    }
}