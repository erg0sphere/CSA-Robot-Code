import com.fazecast.jSerialComm.SerialPort;

import java.io.IOException;


public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        SerialPort sp = SerialPort.getCommPort("COM5");
        sp.setComPortParameters(9600,8,1,0);
        sp.setComPortTimeouts(SerialPort.TIMEOUT_WRITE_BLOCKING,0,0);
        if (sp.openPort()) {
            System.out.println("Port is open :)");
        } else {
            System.out.println("Failed to open port :(");
            return;
        }


        Thread.sleep(5000);

        sp.getOutputStream().write(2);
        sp.getOutputStream().flush();
        System.out.println("Sent number: " + 1);
        Thread.sleep(1000);




        if (sp.closePort()) {
            System.out.println("Port is closed :)");
        } else {
            System.out.println("Failed to close port :(");
            return;
        }
    }
}