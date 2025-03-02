import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.net.Socket;

/**
 * Interface Swing pour interagir avec le serveur C++ via TCP.
 */
public class MediaClientGUI extends JFrame {
    private static final long serialVersionUID = 1L;
    private JTextArea responseArea; // Zone d'affichage des réponses du serveur
    private JTextField mediaNameField; // Champ pour entrer un nom de média
    private Client client; // Connexion avec le serveur

    /**
     * Constructeur de la fenêtre principale.
     */
    public MediaClientGUI() {
        setTitle("Client Média - Interface Graphique");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(500, 400);

        //  Zone d'affichage des réponses
        responseArea = new JTextArea(10, 40);
        responseArea.setEditable(false);
        JScrollPane scrollPane = new JScrollPane(responseArea);

        //  Champ de saisie
        mediaNameField = new JTextField(20);

        // Création des actions
        Action actionDisplayMedia = new ServerAction("Afficher Média", "displayMedia");
        Action actionPlayMedia = new ServerAction("Jouer Média", "playMedia");
        Action actionExit = new ExitAction("Quitter");

        // Menu
        JMenuBar menuBar = new JMenuBar();
        JMenu menu = new JMenu("Options");
        menu.add(new JMenuItem(actionDisplayMedia));
        menu.add(new JMenuItem(actionPlayMedia));
        menu.addSeparator();
        menu.add(new JMenuItem(actionExit));
        menuBar.add(menu);
        setJMenuBar(menuBar);

        // Barre d'outils
        JToolBar toolBar = new JToolBar();
        toolBar.add(actionDisplayMedia);
        toolBar.add(actionPlayMedia);
        toolBar.addSeparator();
        toolBar.add(actionExit);

        //  Organisation des composants
        JPanel inputPanel = new JPanel();
        inputPanel.add(new JLabel("Nom du Média:"));
        inputPanel.add(mediaNameField);

        setLayout(new BorderLayout());
        add(toolBar, BorderLayout.NORTH);
        add(inputPanel, BorderLayout.CENTER);
        add(scrollPane, BorderLayout.SOUTH);

        //  Connexion au serveur
        try {
            client = new Client("localhost", 3331);
            responseArea.append(" Connecté au serveur !\n");
        } catch (Exception e) {
            responseArea.append(" Erreur de connexion au serveur : " + e.getMessage() + "\n");
        }

        pack();
        setVisible(true);
    }

    /**
     * Classe interne pour gérer les actions client/serveur.
     */
    private class ServerAction extends AbstractAction {
        private final String command;

        public ServerAction(String name, String command) {
            super(name);
            this.command = command;
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            String mediaName = mediaNameField.getText().trim();
            if (mediaName.isEmpty()) {
                responseArea.append("Veuillez entrer un nom de média.\n");
                return;
            }

            if (client == null) {
                responseArea.append(" Serveur non connecté.\n");
                return;
            }

            String response = client.send(command + " " + mediaName);
            responseArea.append(" " + command + " " + mediaName + "\n");
            responseArea.append(" Réponse : " + response + "\n");
        }
    }

    /**
     * Classe interne pour fermer l'application proprement.
     */
    private class ExitAction extends AbstractAction {
        public ExitAction(String name) {
            super(name);
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            System.exit(0);
        }
    }

    /**
     * Classe Client pour gérer la connexion au serveur C++.
     */
    private static class Client {
        private Socket sock;
        private BufferedReader input;
        private BufferedWriter output;

        public Client(String host, int port) throws Exception {
            sock = new Socket(host, port);
            input = new BufferedReader(new InputStreamReader(sock.getInputStream()));
            output = new BufferedWriter(new OutputStreamWriter(sock.getOutputStream()));
        }

        public String send(String request) {
            try {
                request += "\n";
                output.write(request, 0, request.length());
                output.flush();
                return input.readLine();
            } catch (Exception e) {
                return "Erreur : " + e.getMessage();
            }
        }
    }

    /**
     * Point d'entrée du programme Java.
     */
    public static void main(String[] args) {
        SwingUtilities.invokeLater(MediaClientGUI::new);
    }
}

