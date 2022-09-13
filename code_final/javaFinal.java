import com.fazecast.jSerialComm.SerialPort;

import java.io.IOException;


public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        SerialPort sp = SerialPort.getCommPort("COM8"); //sets up serial communication between java and the robot
        sp.setComPortParameters(9600,8,1,0);
        sp.setComPortTimeouts(SerialPort.TIMEOUT_WRITE_BLOCKING,0,0);
        if (sp.openPort()) {
            System.out.println("Port is open :)");
        } else {
            System.out.println("Failed to open port :(");
            return;
        }


        Thread.sleep(5000);

        sp.getOutputStream().write(1); //sends the number 1 to the robot brain
        sp.getOutputStream().flush();     //which moves the robot forward
        System.out.println("Sent number: " + 1);
        Thread.sleep(5000);         // moves robot forward for 5 seconds

        sp.getOutputStream().write(3); //sends command 3 to the robot
        sp.getOutputStream().flush();     //which stops the movement of the motor
        System.out.println("Sent number: " + 3);
        Thread.sleep(2000);

        sp.getOutputStream().write(2); //send command 2 to the robot
        sp.getOutputStream().flush();     //which moves it backwards
        System.out.println("Sent number: " + 2);
        Thread.sleep(5000);

        sp.getOutputStream().write(3);  //sends command to stop the robot
        sp.getOutputStream().flush();
        System.out.println("Sent number: " + 3);
        Thread.sleep(2000);



        if (sp.closePort()) {
            System.out.println("Port is closed :)");
        } else {
            System.out.println("Failed to close port :(");
            return;
        }
    }
}
