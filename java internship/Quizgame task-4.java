// Task-4 QUIZ APPLICATION WITH TIMER
import java.util.Scanner;

class QuizQuestion {
    String question;
    String[] options;
    int correctOptionIndex;

    public QuizQuestion(String question, String[] options, int correctOptionIndex) {
        this.question = question;
        this.options = options;
        this.correctOptionIndex = correctOptionIndex;
    }
}

class Quiz {
    QuizQuestion[] questions;
    int score;

    public Quiz(QuizQuestion[] questions) {
        this.questions = questions;
        this.score = 0;
    }

    public void startQuiz() {
        Scanner scanner = new Scanner(System.in);

        for (int i = 0; i < questions.length; i++) {
            System.out.println("Question " + (i + 1) + ": " + questions[i].question);
            for (String option : questions[i].options) {
                System.out.println(option);
            }

            System.out.print("Enter your answer (A/B/C/D): ");
            String userAnswer = scanner.next().toUpperCase();

            if (userAnswer.equals(questions[i].options[questions[i].correctOptionIndex].charAt(0) + "")) {
                System.out.println("Correct!\n");
                score++;
            } else {
                System.out.println("Incorrect!\n");
            }
        }

        System.out.println("Quiz completed! Your score: " + score + " out of " + questions.length);
    }
}

public class Quizgame {
    public static void main(String[] args) {
        QuizQuestion question1 = new QuizQuestion("What is the capital of France?",
                new String[]{"A. London", "B. Paris", "C. Berlin", "D. Rome"}, 1);

        QuizQuestion question2 = new QuizQuestion("Which planet is known as the Red Planet?",
                new String[]{"A. Venus", "B. Mars", "C. Jupiter", "D. Saturn"}, 1);

        QuizQuestion[] quizQuestions = {question1, question2};

        Quiz quiz = new Quiz(quizQuestions);
        quiz.startQuiz();
    }
}
