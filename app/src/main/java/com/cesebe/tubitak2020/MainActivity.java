package com.cesebe.tubitak2020;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.google.firebase.database.DataSnapshot;
import com.google.firebase.database.DatabaseError;
import com.google.firebase.database.DatabaseReference;
import com.google.firebase.database.FirebaseDatabase;
import com.google.firebase.database.ValueEventListener;

public class MainActivity extends AppCompatActivity {


    public void oklistener(){
        Button yukari = findViewById(R.id.yukari_ok);
        Button sag = findViewById(R.id.sag_ok);
        Button sol = findViewById(R.id.sol_ok);
        Button far = findViewById(R.id.far_ok);
        Button oto = findViewById(R.id.oto_ok);
        final TextView textView = findViewById(R.id.db);

        yukari.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_UP){

                    textView.setText("YUKARI");
                    return true;
                }
                else{
                    textView.setText("YUKARI DEĞİL");
                }
                return false;
            }
        });

        sag.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_UP){

                    textView.setText("SAG");
                    return true;
                }
                else{
                    textView.setText("SAG DEĞİL");
                }
                return false;
            }
        });

        sol.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_UP){

                    textView.setText("SOL");
                    return true;
                }
                else{
                    textView.setText("SOL DEĞİL");
                }
                return false;
            }
        });

        far.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_UP){

                    textView.setText("FAR");
                    return true;
                }
                else{
                    textView.setText("FAR DEĞİL");
                }
                return false;
            }
        });

        oto.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                if(event.getAction() == MotionEvent.ACTION_UP){

                    textView.setText("OTO");
                    return true;
                }
                else{
                    textView.setText("OTO DEĞİL");
                }
                return false;
            }
        });
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        final TextView textView = findViewById(R.id.db);
        oklistener();




        FirebaseDatabase database = FirebaseDatabase.getInstance();
        DatabaseReference myRef = database.getReference("message");

        // Read from the database
        myRef.addValueEventListener(new ValueEventListener() {
            @Override
            public void onDataChange(DataSnapshot dataSnapshot) {
                // This method is called once with the initial value and again
                // whenever data at this location is updated.

                String value = dataSnapshot.getValue(String.class);
                textView.setText(value);


            }

            @Override
            public void onCancelled(DatabaseError error) {
                // Failed to read value

            }
        });
    }
}
