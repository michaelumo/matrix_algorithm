/*! @file matrix_algorithm/matrix_algorithm.h
 *  @version 0.0.1
 *  @date Dec 15 2019
 *
 *  @brief
 *  Algorithms for matrix manipulation.
 *  Algorithms list:
 *		- Tridiagonal matrix algorithm
 *
 *  @Copyright (c) 2019 Michael O. Umenyi
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */


#ifndef __MATRIX_ALGORITHM_H__
#define __MATRIX_ALGORITHM_H__

class TDMA{ //Tridiagonal matrix algorithm
	private:
		std::vector<double> *a;
		std::vector<double> *b;
		std::vector<double> *c;
		std::vector<double> *d;
		double cstar(int i){
			if(i == 1)return c->at(i)/b->at(i);
			else return c->at(i)/(b->at(i)-a->at(i)*cstar(i-1));
		}

		double dstar(int i){
			if(i == 1)return d->at(i)/b->at(i);
			else return (d->at(i)-a->at(i)*dstar(i-1))/(b->at(i)-a->at(i)*cstar(i-1));
		}

	public:
		TDMA(){};
		~TDMA(){};

		Matrix tdma(std::vector<double> &A, std::vector<double> &B,
		  					std::vector<double> &C, std::vector<double> &D){
			a = &A;
			b = &B;
			c = &C;
			d = &D;
			std::vector<double> f;
			f.push_back(dstar(d->size()-1));
			for(int i = b->size()-2; i > 0; i--){
				f.insert(f.begin(), dstar(i)-cstar(i)*f[0]);
			}
			f.insert(f.begin(), 0);
			f.push_back(0);
			Matrix val(f.size(),1);
			val.setvalue(f);
			return val;
		}
};

#endif
