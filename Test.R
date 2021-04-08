setwd("C:/Users/201711137/Documents/data")
Sys.setlocale("LC_ALL","C")

DF_Student <- read.csv(file="student_info.csv")
DF_Mobile <- read.csv(file="mobile_info.csv")
DF_Mobile_Battery <- read.csv(file = "mobile_battery.csv")
DF_Gender <- read.csv(file = "frequency_gender.csv")
DF_Cross <- read.csv(file = "cross_gender.csv")
DF_Student_Body <- read.csv(file = "student_body.csv")
DF <- read.csv(file="coffee_sales.csv")
DF_Student_Study <- read.csv(file="student_study.csv")
DF_a_milk <- read.csv(file="milk_content_A.csv")
DF_b_milk <- read.csv(file="milk_content_B.csv")
DF_Student_Exam <- read.csv(file = "student_exam.csv")

DF[2]
DF[c(2,3)]
DF[DF$Owner == "M",]

DF_Student[3]
DF_Student[c(4,7,10),]
DF_Student[DF_Student$X...ID == '3',]
DF_Student[DF_Student$HP == "Samsung",]
attach(DF_Student)
HP[1]

DF_Mobile[DF_Mobile$Owner == "M",]
DF_Mobile[DF_Mobile$Battery_Capacity > 2000,]

attach(DF_Mobile)
Brand[5]

summary(DF_Mobile)
table(DF_Cross$Grade,DF_Gender$Gender)
table(DF_Student_Body$Grade, DF_Student_Body$Gender)

table(DF$Menu, DF$Size)

TBL_sales <- table(DF$Menu)
prop.table(TBL_sales)

TBL_student <- table(DF_Student_Body$Grade)
TBL_Student_Gender <- table(DF_Cross)
prop.table(TBL_student)

barplot(TBL_student)
barplot(TBL_Student_Gender, legend = TRUE)

TBL_Coffee <- table(DF$Size, DF$Menu)
barplot(TBL_Coffee)

TBL_Student_Blood <- table(DF_Student_Body$BloodType)
barplot(TBL_Student_Blood, legend = TRUE, col = rainbow(4), xlab = "Blood Type", ylab = "Count")

pie(table(DF$Menu))
pie(table(DF_Student_Study$Free_Time))
pie(table(DF_Student_Body$BloodType))

table(DF_Mobile_Battery$Gender)
TBL_Battery <- table(DF_Mobile_Battery$Brand)
prop.table(TBL_Battery)

TBL_Battery_Cross <- table(DF_Mobile_Battery$Brand, DF_Mobile_Battery$Gender)
TBL_Battery_Cross
barplot(TBL_Battery_Cross, col = rainbow(3), xlab = "M/F", ylab = "Brand")
abline(h = 10, col = "Red", lty = 8)

install.packages("plotrix")
library(plotrix)

instance <- table(DF_Mobile_Battery$Color)
label <- table(DF_Mobile_Battery$Color)
pct <- round(instance/sum(instance) * 100)
label <- paste(names(instance), pct, "%")
pie3D(instance, labels = label)

cut_body <- cut(DF_Student_Body$Weight, breaks = 3)
p <- table(cut_body) 
hist(p)

cut_body <- cut(DF_Student_Body$Weight, breaks = c(40,50,60,70,80,90))
p <- table(cut_body)
hist(p)

hist(DF_a_milk$content)
hist(DF_b_milk$content)

boxplot(as.matrix(data.frame(DF_a_milk$content, DF_b_milk$content)))
plot(DF_Student_Study$Time, DF_Student_Study$Grade)

install.packages("corrplot")
library(corrplot)

m <- cor(data.frame(DF_Student_Body$Age, DF_Student_Body$Grade, DF_Student_Body$Weight, DF_Student_Body$Height))

corrplot(m, method = "box")

a <- data.frame(DF_Mobile_Battery)
summary(a)
str(a)

DF_Student_Study$Grade

a <- DF_Student_Study$Time && DF_Student_Study$Grade == "1"
b <- DF_Student_Study$Time && DF_Student_Study$Grade == "2"
c <- DF_Student_Study$Time && DF_Student_Study$Grade == "3"
d <- DF_Student_Study$Time && DF_Student_Study$Grade == "4"

boxplot(as.matrix(data.frame(a,b,c,d)), ylim = c(0, 1))

DF_Student <- read.csv(file="adv_sales.csv")
plot(DF_Student$ADV, DF_Student$Sales, ylim = c(0, 1))

mean(c(1:50))

mean(DF_Student_Exam$Class_A)
mean(DF_Student_Exam$Class_B)

DF_Coffee_Location <- read.csv(file = "coffee_monthly_location_sales.csv")
mean(DF_Coffee_Location$No_Seoul)
mean(DF_Coffee_Location$No_Gangneung)
mean(DF_Coffee_Location$No_Busan)

median(c(1,10,5,8,9,20))
median(c(1,2,3,4))

median(DF_Student_Exam$Class_A)
median(DF_Student_Exam$Class_B)

mode(DF_Student_Exam$Class_B)

var(c(60, 70, 80, 90, 100))
var(DF_Student_Exam$Class_A)
var(DF_Student_Exam$Class_B)

sd(DF_Coffee_Location$No_Seoul)
sd(DF_Coffee_Location$No_Gangneung)
sd(DF_Coffee_Location$No_Busan)

sd(DF_Student_Exam$Class_A)
sd(DF_Student_Exam$Class_B)

DF_Visitor <- read.csv(file = "blog_visitor.csv")

range(DF_Visitor)

range(DF_Student_Exam$Class_A)
range(DF_Student_Exam$Class_B)

summary(DF_Visitor)
summary(DF_Student_Exam)
