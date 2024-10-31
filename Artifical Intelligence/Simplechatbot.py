# Simple Chatbot about IOST, TU courses
responses = {
    "hello": "Hi! Welcome to IOST, TU course chatbot. How can I help you?",
    "about": "The Institute of Science and Technology (IOST) is a constituent campus of Tribhuvan University (TU) that offers various undergraduate and graduate programs in science and technology.",
    "courses": "We offer the following courses: Bachelor of Science in Computer Science and Information Technology (BSc CSIT), Bachelor of Science in Electronics and Communication Engineering (BSc ECE), Bachelor of Science in Civil Engineering (BSc CE), and more.",
    "bsc csit": "Our BSc CSIT program is a four-year undergraduate degree that covers computer science and information technology. It includes courses on programming, data structures, algorithms, computer networks, and more.",
    "bsc ece": "Our BSc ECE program is a four-year undergraduate degree that covers electronics and communication engineering. It includes courses on electronics, communication systems, microprocessors, and more.",
    "bsc ce": "Our BSc CE program is a four-year undergraduate degree that covers civil engineering. It includes courses on structural analysis, transportation engineering, water resources engineering, and more.",
    "masters": "We also offer various master's programs, including Master of Science in Computer Science and Information Technology (MSc CSIT), Master of Science in Electronics and Communication Engineering (MSc ECE), and more.",
    "eligibility": "The eligibility criteria for our undergraduate programs is a minimum of 45% in 10+2 or equivalent in science stream. For master's programs, a bachelor's degree in a relevant field is required.",
    "fee": "The course fee for our undergraduate programs is NPR 1,20,000 per year, and for master's programs, it is NPR 1,50,000 per year.",
    "bsc csit fee": "The course fee for our BSc CSIT program is NPR 1,20,000 per year.",
    "bsc ece fee": "The course fee for our BSc ECE program is NPR 1,20,000 per year.",
    "bsc ce fee": "The course fee for our BSc CE program is NPR 1,20,000 per year.",
    "msc csit fee": "The course fee for our MSc CSIT program is NPR 1,50,000 per year.",
    "msc ece fee": "The course fee for our MSc ECE program is NPR 1,50,000 per year.",
    "query": "Please ask your query, and I'll do my best to answer it."
}



def chatbot():
    print("Welcome to IOST, TU course chatbot!")
    while True:
        user_input = input("You: ").lower()
        if user_input in responses:
            print("Chatbot:", responses[user_input])
        elif user_input == "exit":
            print("Chatbot: Goodbye!")
            break
        else:
            print("Chatbot: Sorry, I didn't understand that. Please try again.")

chatbot()
