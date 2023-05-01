# Define the questions and answers for the quiz
questions = [
  { question: "What is the capital of France?", 
    answers: [
      "Madrid", 
      "Paris", 
      "Rome", 
      "Berlin"
    ], 
    correct_answer: 1 
  },
  { question: "What is the largest planet in our solar system?", 
    answers: [
      "Mars", 
      "Venus", 
      "Jupiter", 
      "Saturn"
    ], 
    correct_answer: 2 
  },
  { question: "What is the tallest mountain in the world?", 
    answers: [
      "Mount Kilimanjaro", 
      "Mount Everest", 
      "Mount Fuji", 
      "Mount Denali"
    ], 
    correct_answer: 1 
  }
]

# Define a function to ask a question and return the user's answer
def ask_question(question)
  puts question[:question]
  question[:answers].each_with_index do |answer, index|
    puts "#{index + 1}. #{answer}"
  end
  print "Enter your answer (1-#{question[:answers].length}): "
  gets.chomp.to_i
end

# Define a function to grade the user's answers and return their score
def grade_quiz(questions)
  score = 0
  questions.each do |question|
    user_answer = ask_question(question)
    if user_answer == question[:correct_answer]
      puts "Correct!"
      score += 1
    else
      puts "Incorrect. The correct answer is #{question[:answers][question[:correct_answer]]}."
    end
  end
  puts "You scored #{score}/#{questions.length} on the quiz."
end

# Call the grade_quiz function to start the quiz
grade_quiz(questions)
