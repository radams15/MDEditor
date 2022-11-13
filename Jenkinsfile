pipeline {
	agent none

	stages {
		stage('Linux') {
			agent {
				dockerfile true
			}

			sh 'mkdir build && cd build && cmake .. && make -j8'

			archiveArtifacts artifacts: 'MDEditor'
		}
	}
}