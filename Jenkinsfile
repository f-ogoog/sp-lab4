pipeline {
    agent any

    stages {
        stage('Checkout') {
            steps {
                git url: 'https://gitea.com/JohnTuwa/SP_Lab4.git', credentialsId: 'e13921d3-a2d8-4ba2-baec-a7eecfab5d93'
            }
        }
        
        stage('Build') {
            steps {
                // Крок для збірки проекту з Visual Studio
                // Встановіть правильні шляхи до рішення/проекту та параметри MSBuild
                bat '"C:\\Program Files\\Microsoft Visual Studio\\2022\\Community\\MSBuild\\Current\\Bin\\MSBuild.exe" test_repos.sln /t:Build /p:Configuration=Release'
            }
        }

        stage('Test') {
            steps {
                // Команди для запуску тестів
                bat "x64\\Debug\\test_repos.exe --gtest_output=xml:test_report.xml"
            }
        }
    }

    post {
    always {
        // Publish test results using the junit step
    
        junit 'test_report.xml'
    }
}
}