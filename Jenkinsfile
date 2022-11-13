pipeline {
	agent none

	stages {
		stage('Linux') {
			agent {
				dockerfile true
			}

			steps{
				sh 'mkdir -p build && cd build && cmake .. && make -j8'

				archiveArtifacts artifacts: 'build/MDEditor'
			}
		}
	}
}